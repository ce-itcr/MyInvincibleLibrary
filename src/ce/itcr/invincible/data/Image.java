package ce.itcr.invincible.data;

public class Image {

    private int id;
    private String parentId;
    private String name;
    private String author;
    private int year;
    private int size;
    private String description;
    private String metaData;
    private String compressedData;

    public Image() { }

    public Image(int id, String parentId, String name, String author, int year, int size, String description, String metaData, String compressedData) {
        this.id = id;
        this.parentId = parentId;
        this.name = name;
        this.author = author;
        this.year = year;
        this.size = size;
        this.description = description;
        this.metaData = metaData;
        this.compressedData = compressedData;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getParentId() {
        return parentId;
    }

    public void setParentId(String parentId) {
        this.parentId = parentId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getMetaData() {
        return metaData;
    }

    public void setMetaData(String metaData) {
        this.metaData = metaData;
    }

    public String getCompressedData() {
        return compressedData;
    }

    public void setCompressedData(String compressedData) {
        this.compressedData = compressedData;
    }
}
