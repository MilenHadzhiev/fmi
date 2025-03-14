package Items;

import java.text.ParseException;
import java.util.Date;
import utils.Utils;

public class ItemEntry {
    protected final int amount;
    protected final Date date;

    protected ItemEntry(int amount, Date date) {
        this.amount = amount;
        this.date = date;
    }

    protected ItemEntry(int amount, String date) throws ParseException {
        this.amount = amount;
        this.date = Utils.parseStringToDate(date);
    }

    public ItemEntry(ItemBuilder<?> builder) {
        this.amount = builder.amount;
        this.date = builder.date;
    }

    @Override
    public String toString() {
        return this.amount + " on " + this.date;
    }

    public static class ItemBuilder<T extends ItemBuilder<T>> {
        private int amount;
        private Date date;

        protected T self() {
            return (T) this;
        }
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

        public ItemEntry build() {
            return new ItemEntry(this);
        }
    }
}
