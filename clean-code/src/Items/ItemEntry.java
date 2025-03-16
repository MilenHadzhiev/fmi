package Items;

import java.text.ParseException;
import java.util.Date;

import org.json.JSONObject;
import utils.Utils;

abstract public class ItemEntry {
    protected final int amount;
    protected final Date date;

    abstract String getItemType();

    public ItemEntry(ItemBuilder<?> builder) {
        this.amount = builder.amount;
        this.date = builder.date;
    }

    protected ItemEntry(int amount, String date) throws ParseException {
        this.amount = amount;
        this.date = Utils.parseStringToDate(date);
    }

    public JSONObject toJSONObject() {
        JSONObject json = new JSONObject();
        json.put("item_type", this.getItemType());
        json.put("amount", this.amount);
        json.put("date", this.date.toString());
        return json;
    }

    public String toJsonString() {
        return this.toJSONObject().toString();
    }

    @Override
    public String toString() {
        return this.amount + " on " + this.date;
    }

    public abstract static class ItemBuilder<T extends ItemBuilder<T>> {
        private int amount;
        private Date date;

        protected abstract T self();

        public T setAmount(int amount) {
            this.amount = amount;
            return self();
        }

        public T setDate(Date date) {
            this.date = date;
            return self();
        }

        public T setDate(String date) throws ParseException {
            this.date = Utils.parseStringToDate(date);
            return self();
        }

        public abstract ItemEntry build();
    }
}

