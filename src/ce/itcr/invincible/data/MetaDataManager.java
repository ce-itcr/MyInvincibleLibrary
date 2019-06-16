package ce.itcr.invincible.data;

import java.util.*;
import java.sql.*;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();
    private static final String DB_URL = "mongodb://localhost:27017/gallery";
    private static final String USER = "username";
    private static final String PASS = "password";
    private Connection connection;

    private MetaDataManager() {
        connect();
    }

    public static MetaDataManager getInstance() {
        return instance;
    }

    public boolean INSERT(List<Image> images) throws SQLException {
        Statement statement = connection.createStatement();
        String sql;
        ResultSet response = null;

        int cont=0;
        while(images.size() > cont) {
            sql = "INSERT INTO images " +
                    "VALUES (images[cont].parentId, images[cont].name, images[cont].author," +
                    "images[cont].year, images[cont].size, images[cont].description, images[cont].metaData)";
            response = statement.executeQuery(sql);
            cont++;
        }

        if (response != null) response.close();
        statement.close();
        return true;
    }

    public List<Image> SELECT(List<String> imagesId) throws SQLException {
        Statement statement = connection.createStatement();
        String sql;
        ResultSet response = null;
        List<Image> images = new ArrayList<>();

        int cont=0;
        while(imagesId.size() > cont) {
            sql = "SELECT ID, PARENT_ID, NAME, AUTHOR, YEAR, SIZE, DESCRIPTION" +
                    " FROM images" +
                    " WHERE ID = " + imagesId.get(cont);
            response = statement.executeQuery(sql);
            images.add(createImage(response));
            cont++;
        }

        if (response != null) response.close();
        statement.close();
        return images;
    }

    public boolean DELETE(List<String> imagesId) throws SQLException {
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

    public List<Image> UPDATE(List<Image> images) throws SQLException {
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
    }



    private void connect() {
        try {
             connection = DriverManager.getConnection(DB_URL, USER, PASS);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private Image createImage(ResultSet response) throws SQLException {
        int id = Integer.parseInt(response.getString("ID"));
        String parentId = response.getString("PARENT_ID");
        String name = response.getString("NAME");
        String author = response.getString("AUTHOR");
        int year = Integer.parseInt(response.getString("YEAR"));
        int size = Integer.parseInt(response.getString("SIZE"));
        String description = response.getString("DESCRIPTION");
        String metaData = response.getString("META_DATA");

        Image image = new Image(parentId, name, author, year, size, description);
        image.setId(id);
        image.setMetaData(metaData);
        return image;
    }
}
