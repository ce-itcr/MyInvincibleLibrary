package ce.itcr.invincible.data;

import com.mongodb.Block;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

import java.util.*;
import java.util.function.Consumer;

import static com.mongodb.client.model.Filters.eq;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();
    private static final String DB_URL = "mongodb://localhost:27017";
    private static final String DB_NAME = "gallery";
    private static final String DB_COLLECTION = "images";
    private static final String USER = "username";
    private static final String PASS = "password";
    private MongoCollection<Document> mongoCollection;
    List<Image> images = new ArrayList<>();

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

    public boolean INSERT(List<Image> images) {
        List<Document> documents = new ArrayList<>();
        for (Image image : images) {
            documents.add(createDocument(image));
        }
        mongoCollection.insertMany(documents);
        return true;
    }

    /**
    public boolean DELETE(List<String> imagesId) {
        Statement statement = connection.createStatement();
        String sql;
        ResultSet response = null;

        int cont=0;
        while(imagesId.size() > cont) {
            sql = "DELETE FROM images " +
                    "WHERE id = imagesId[cont].Id";
            response = statement.executeQuery(sql);
            cont++;
        }

        if (response != null) response.close();
        statement.close();
        return true;
    }

    public List<Image> UPDATE(List<Image> images) {
        Statement statement = connection.createStatement();
        String sql;
        ResultSet response = null;
        List<Image> newImages = new ArrayList<>();

        int cont = 0;
        while (images.size() > cont) {
            sql = "UPDATE images " +
                    "SET parentId = images[cont].parentId, name = images[cont].name, author = images[cont].author, year = images[cont].year," +
                    " size = images[cont].size, description = images[cont].description, metaData = images[cont].metaData," +
                    " compressedData = images[cont].compressedData";
            response = statement.executeQuery(sql);
            newImages.add(createImage(response));
            cont++;
        }

        if (response != null) response.close();
        statement.close();
        return newImages;
    }

    public static String getDbUrl() {
        return DB_URL;
    }

    public static String getUSER() {
        return USER;
    }

    public static String getPASS() {
        return PASS;
    }**/

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

    private Document createDocument(Image image) {
        return new Document("parentId", image.getParentId())
                .append("name", image.getName())
                .append("author", image.getAuthor())
                .append("year", image.getYear())
                .append("size", image.getSize())
                .append("description", image.getDescription())
                .append("metaData", image.getMetaData());
    }
}
