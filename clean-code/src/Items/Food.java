package Items;

import org.json.JSONObject;

public class Food extends ItemEntry {
    private final String foodName;
    private final String description;
    private final int servingSize;
    private final int servingsPerContainer;
    private final int caloriesPerServing;
    private final int carbsPerServing;
    private final int fatPerServing;
    private final int proteinPerServing;

    public String getItemType() {
        return "Food";
    }

    public Food(FoodBuilder builder) {
        super(builder);
        this.foodName = builder.foodName;
        this.description = builder.description;
        this.servingSize = builder.servingSize;
        this.servingsPerContainer = builder.servingsPerContainer;
        this.caloriesPerServing = builder.caloriesPerServing;
        this.carbsPerServing = builder.carbsPerServing;
        this.fatPerServing = builder.fatPerServing;
        this.proteinPerServing = builder.proteinPerServing;
    }

    @Override
    public JSONObject toJSONObject() {
        JSONObject json = super.toJSONObject();
        json.put("foodName", foodName);
        json.put("description", description);
        json.put("servingSize", servingSize);
        json.put("servingsPerContainer", servingsPerContainer);
        json.put("caloriesPerServing", caloriesPerServing);
        json.put("carbsPerServing", carbsPerServing);
        json.put("fatPerServing", fatPerServing);
        json.put("proteinPerServing", proteinPerServing);
        return json;
    }

    public static class FoodBuilder extends ItemBuilder<FoodBuilder> {
        private String foodName;
        private String description;
        private int servingSize;
        private int servingsPerContainer;
        private int caloriesPerServing;
        private int carbsPerServing;
        private int fatPerServing;
        private int proteinPerServing;

        protected FoodBuilder self() {
            return (FoodBuilder) this;
        }

        public FoodBuilder setFoodName(String foodName) {
            this.foodName = foodName;
            return this;
        }

        public FoodBuilder setDescription(String description) {
            this.description = description;
            return this;
        }

        public FoodBuilder setServingSize(int servingSize) {
            this.servingSize = servingSize;
            return this;
        }

        public FoodBuilder setServingsPerContainer(int servingsPerContainer) {
            this.servingsPerContainer = servingsPerContainer;
            return this;
        }

        public FoodBuilder setCaloriesPerServing(int caloriesPerServing) {
            this.caloriesPerServing = caloriesPerServing;
            return this;
        }

        public FoodBuilder setCarbsPerServing(int carbsPerServing) {
            this.carbsPerServing = carbsPerServing;
            return this;
        }

        public FoodBuilder setFatPerServing(int fatPerServing) {
            this.fatPerServing = fatPerServing;
            return this;
        }

        public FoodBuilder setProteinPerServing(int proteinPerServing) {
            this.proteinPerServing = proteinPerServing;
            return this;
        }

        public Food build() {
            return new Food(this);
        }
    }
}
