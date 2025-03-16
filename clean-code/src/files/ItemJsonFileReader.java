package files;

import Items.ItemEntry;
import org.json.JSONArray;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ItemJsonFileReader {
    private final String path;

    public ItemJsonFileReader(String path) throws IOException {
        Path filePath = Paths.get(path);
        if (!(Files.exists(filePath) && Files.isRegularFile(filePath))) {
            throw new IOException();
        }
        this.path = path;
    }

//    public ItemEntry[] read() throws IOException {
//
//    }

    public JSONArray readJsonArray() throws IOException {
        File file = new File(this.path);
        if (!file.exists() || file.length() == 0) {
            return new JSONArray();
        }
        try (FileReader fileReader = new FileReader(file)) {
            char[] buffer = new char[(int) file.length()];
            fileReader.read(buffer);
            return new JSONArray(new String(buffer));
        } catch (IOException e) {
            e.printStackTrace();
            throw e;
        }
    }
}
