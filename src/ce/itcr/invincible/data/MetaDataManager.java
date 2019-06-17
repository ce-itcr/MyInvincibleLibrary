package ce.itcr.invincible.data;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;
import org.bson.types.ObjectId;

import java.util.*;
import java.util.function.Consumer;

import static com.mongodb.client.model.Filters.eq;
import static com.mongodb.client.model.Filters.and;
import static com.mongodb.client.model.Filters.not;
import static com.mongodb.client.model.Updates.combine;
import static com.mongodb.client.model.Updates.set;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();
    private static final String DB_URL = "mongodb://localhost:27017";
    private static final String DB_NAME = "gallery";
    private static final String DB_IMG_COLLECTION = "images";
    private static final String DB_FOLDER_COLLECTION = "folders";
    private static final String USER = "username";
    private static final String PASS = "password";
    private MongoCollection<Document> imagesCollection;
    private MongoCollection<Document> foldersCollection;
    private List<Image> images = new ArrayList<>();

    private MetaDataManager() {
        MongoClient mongoClient = MongoClients.create(DB_URL);
        MongoDatabase mongoDatabase = mongoClient.getDatabase(DB_NAME);
        imagesCollection = mongoDatabase.getCollection(DB_IMG_COLLECTION);
        foldersCollection = mongoDatabase.getCollection(DB_FOLDER_COLLECTION);
    }

    public static MetaDataManager getInstance() {
        return instance;
    }

    public List<Image> SELECT(String folderId) {
        images.clear();

        // Makes request and process
        Consumer<Document> consumer = this::createImage;
        imagesCollection.find(eq("parentId", folderId)).forEach(consumer);

        return images;
    }

    public boolean INSERT(String folderId, List<Image> images) {
        List<Document> documents = new ArrayList<>();
        for (Image image : images) {
            documents.add(createDocument(folderId, image));
        }
        imagesCollection.insertMany(documents);
        return true;
    }

    public boolean DELETE(String folderId) {
        imagesCollection.deleteMany(eq("parentId", folderId));
        return true;
    }

    public List<Image> UPDATE(String folderId, List<Image> images) {
        for (Image image : images) {
            imagesCollection.updateOne(eq("_id", new ObjectId(image.getId())),
                    combine(set("parentId", folderId),
                            set("name", image.getName()),
                            set("author", image.getAuthor()),
                            set("year", image.getYear()),
                            set("size", image.getSize()),
                            set("description", image.getDescription()),
                            set("metaData", image.getMetaData())));
        }
        return SELECT(folderId);
    }

    public long insertSubFolder(String parentId) {
        long subFolders = countSubFolders(parentId);
        String folderId = parentId + "." + subFolders;
        Document doc = new Document("parentId", parentId)
                            .append("folderId", folderId)
                            .append("subFolders", 0);
        foldersCollection.insertOne(doc);
        updateSubFolderCount(parentId, subFolders + 1);
        return subFolders;
    }

    public void deleteSubFolder(String folderId) {
        Consumer<Document> consumer = this::deleteFolder;
        foldersCollection.find((eq("parentId", folderId))).forEach(consumer);
        foldersCollection.deleteOne(and(eq("folderId", folderId),
                                    not(eq("parentId", "root"))));
        DELETE(folderId);
        updateParentCount(folderId);
    }

    public long countSubFolders(String folderId) {
        return foldersCollection.countDocuments(eq("parentId", folderId));
    }

    public static String getDbUrl() {
        return DB_URL;
    }

    public static String getUSER() {
        return USER;
    }

    public static String getPASS() {
        return PASS;
    }

    private void updateSubFolderCount(String folderId, long subFolderCount) {
        foldersCollection.updateOne(eq("folderId", folderId),
                combine(set("subFolders", subFolderCount)));
    }

    private void updateParentCount(String subFolderId) {
        int length = subFolderId.length();
        String parentId = subFolderId;

        if (subFolderId.contains(".")) {
            while (parentId.charAt(length - 1) != '.') {
                parentId = parentId.substring(0, parentId.length() - 1);
                length = parentId.length();
            }
            parentId = parentId.substring(0, parentId.length() - 1);
        }

        long foldersCount = countSubFolders(parentId);
        updateSubFolderCount(parentId, foldersCount);
    }

    private void deleteFolder(Document folder) {
        String folderId = folder.getString("folderId");
        DELETE(folderId);
        deleteSubFolder(folderId);
    }

    private void createImage(Document response) {
        String id = response.getObjectId("_id").toString();
        String parentId = response.getString("parentId");
        String name = response.getString("name");
        String author = response.getString("author");
        int year = response.getInteger("year");
        int size = response.getInteger("size");
        String description = response.getString("description");
        String metaData = response.getString("metaData");

        Image image = new Image(parentId, name, author, year, size, description);
        image.setId(id);
        image.setMetaData(metaData);

        images.add(image);
    }

    private Document createDocument(String folderId, Image image) {
        return new Document("parentId", folderId)
                .append("name", image.getName())
                .append("author", image.getAuthor())
                .append("year", image.getYear())
                .append("size", image.getSize())
                .append("description", image.getDescription())
                .append("metaData", image.getMetaData());
    }
}
