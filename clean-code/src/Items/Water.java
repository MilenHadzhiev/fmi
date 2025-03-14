package Items;

public class Water extends ItemEntry {
    public Water(ItemBuilder<?> builder) {
        super(builder);
    }

    @Override
    public String toString() {
        return this.amount + "ml water on " + this.date;
    }
}
