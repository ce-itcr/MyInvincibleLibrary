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
import static com.mongodb.client.model.Updates.combine;
import static com.mongodb.client.model.Updates.set;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();
    private static final String DB_URL = "mongodb://localhost:27017";
    private static final String DB_NAME = "gallery";
    private static final String DB_COLLECTION = "images";
    private static final String USER = "username";
    private static final String PASS = "password";
    private MongoCollection<Document> mongoCollection;
    private List<Image> images = new ArrayList<>();

    private MetaDataManager() {
        MongoClient mongoClient = MongoClients.create(DB_URL);
        MongoDatabase mongoDatabase = mongoClient.getDatabase(DB_NAME);
        mongoCollection = mongoDatabase.getCollection(DB_COLLECTION);
    }

    public static MetaDataManager getInstance() {
        return instance;
    }

    public List<Image> SELECT(String folderId) {
        images.clear();

        // Makes request and process
        Consumer<Document> consumer = this::createImage;
        mongoCollection.find(eq("parentId", folderId)).forEach(consumer);

        return images;
    }

    public boolean INSERT(String folderId, List<Image> images) {
        List<Document> documents = new ArrayList<>();
        for (Image image : images) {
            documents.add(createDocument(folderId, image));
        }
        mongoCollection.insertMany(documents);
        return true;
    }

    public boolean DELETE(String folderId) {
        mongoCollection.deleteMany(eq("parentId", folderId));
        return true;
    }

    public List<Image> UPDATE(String folderId, List<Image> images) {
        for (Image image : images) {
            mongoCollection.updateOne(eq("_id", new ObjectId(image.getId())),
                    combine(set("parentId", image.getParentId()),
                            set("name", image.getName()),
                            set("author", image.getAuthor()),
                            set("year", image.getYear()),
                            set("size", image.getSize()),
                            set("description", image.getDescription()),
                            set("metaData", image.getMetaData())));
        }
        return SELECT(folderId);
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
