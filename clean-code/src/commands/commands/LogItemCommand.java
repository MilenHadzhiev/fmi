package commands.commands;

import Items.ItemEntry;
import files.ItemJsonFileWriter;

import java.io.IOException;

public class LogItemCommand extends BaseCommand {
    protected ItemEntry item;
    protected ItemJsonFileWriter writer;

    public LogItemCommand(ItemEntry itemEntry, String filePath) {
        this.item = itemEntry;
        this.writer = new ItemJsonFileWriter(filePath);
    }

    public void execute() throws IOException {
        this.writer.write(item);
    }
}
