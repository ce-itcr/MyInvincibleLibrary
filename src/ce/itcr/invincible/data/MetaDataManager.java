package ce.itcr.invincible.data;

import java.util.List;
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
        String sql = "INSERT ...";
        ResultSet response = statement.executeQuery(sql);

        response.close();
        statement.close();
        return false;
    }

    public List<Image> SELECT(List<String> imagesId) {
        return null;
    }

    public boolean DELETE(List<String> imagesId) {
        return false;
    }

    public boolean UPDATE(List<Image> images) {
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
