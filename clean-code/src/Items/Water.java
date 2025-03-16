package Items;

public class Water extends ItemEntry {
    public Water(WaterBuilder builder) {
        super(builder);
    }

    public String getItemType() {
        return "Water";
    }
    @Override
    public String toString() {
        return this.amount + "ml water on " + this.date;
    }

    public static class WaterBuilder extends ItemBuilder<WaterBuilder> {
        protected WaterBuilder self() {
            return (WaterBuilder) this;
        }

        public Water build() {
            return new Water(this);
        }
    }
}
