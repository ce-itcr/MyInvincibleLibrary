package ce.itcr.invincible.data;

import java.util.*;
import java.sql.*;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();
    private static final String DB_URL = "mongodb://localhost:27017/gallery";
    private static final String USER = "username";
    private static final String PASS = "password";
    private Connection connection;

    int id;
    String parentId;
    String name;
    String author;
    int year;
    int size;
    String description;
    String metaData;
    String compressedData;

    private MetaDataManager() {
        connect();
    }

    public static MetaDataManager getInstance() {
        return instance;
    }

    public boolean INSERT(List<Image> images) throws SQLException {
        int cont=0;
        while(images.size>cont) {
            Statement statement = connection.createStatement();
            String sql = "INSERT INTO images " +
                    "VALUES (images[cont].id, images[cont].parentId, images[cont].name, images[cont].author," +
                    " images[cont].year, images[cont].size, images[cont].description, images[cont].metaData," +
                    " images[cont].compressedData)";
            stmt.executeUpdate(sql);
            ResultSet response = statement.executeQuery(sql);

            response.close();
            statement.close();
            cont++;
        }
        return false;
    }

    public List<Image> SELECT(List<String> imagesId) {
        int cont=0;
        while(imagesId.size>cont) {
            Statement statement = connection.createStatement();
            String sql = "SELECT images[cont].id, images[cont].parentId, images[cont].name, images[cont].author," +
                    " images[cont].year, images[cont].size, images[cont].description, images[cont].metaData," +
                    " images[cont].compressedData FROM images";
            ResultSet response = statement.executeQuery(sql);

            id = response.getId("id");
            parentId = response.getParentId("parentId");
            name = response.getName("name");
            author = response.getAuthor("author");
            year = response.getYear("year");
            size = response.getSize("size");
            desctription = response.getDescription("description");
            metaData = response.getMetaData("metaData");
            compressedData = response.getCompressedData("compressedData");

            response.close();
            statement.close();
            cont++;
        }
        return null;
    }

    public boolean DELETE(List<String> imagesId) {
        int cont=0;
        while(imagesId.size>cont) {
            Statement statement = connection.createStatement();
            String sql = "DELETE FROM images " +
                    "WHERE id = imagesId[cont].Id";
            stmt.executeUpdate(sql);
            ResultSet response = statement.executeQuery(sql);
            cont++;
        }
        return false;
    }

    public boolean UPDATE(List<Image> images) {
        int cont = 0;
        while (images.size > cont) {
            Statement statement = connection.createStatement();
            String sql = "UPDATE images " +
                    "SET parentId = images[cont].parentId, name = images[cont].name, author = images[cont].author, year = images[cont].year," +
                    " size = images[cont].size, description = images[cont].description, metaData = images[cont].metaData," +
                    " compressedData = images[cont].compressedData";
            stmt.executeUpdate(sql);
            ResultSet response = statement.executeQuery(sql);
            cont++;
        }
        return false;
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

    private void connect() {
        try {
             connection = DriverManager.getConnection(DB_URL, USER, PASS);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
