package files;

import Items.ItemEntry;
import org.json.JSONArray;

import java.io.FileWriter;
import java.io.IOException;

public class ItemJsonFileWriter {
    private final String path;

    public ItemJsonFileWriter(String path) {
        this.path = path;
    }

    public void write(ItemEntry item) throws IOException {
        ItemJsonFileReader reader = new ItemJsonFileReader(this.path);
        JSONArray jsonArray = reader.readJsonArray();
        jsonArray.put(item.toJSONObject());
        this.writeJsonArray(jsonArray);
    }

    private void writeJsonArray(JSONArray jsonArray) throws IOException {
        try (FileWriter fileWriter = new FileWriter(this.path)) {
            fileWriter.write(jsonArray.toString(4));
        } catch (IOException e) {
            e.printStackTrace();
            throw e;
        }
    }
}