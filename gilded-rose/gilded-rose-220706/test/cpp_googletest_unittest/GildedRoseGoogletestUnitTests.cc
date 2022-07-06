#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, updateQuality_itemName) {
    vector<Item> items;
    items.push_back(Item("Foo", 5, 5));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
}

TEST(GildedRoseTest, updateQuality_itemSellin) {
    vector<Item> items;
    items.push_back(Item("Foo", 5, 5));

    GildedRose gildedRose(items);
    gildedRose.updateQuality();

    ASSERT_EQ(4, gildedRose.items[0].sellIn);
}

TEST(GildedRoseTest, updateQuality_itemQuality) {
    vector<Item> items;
    items.emplace_back(Item("foo", 5, 5));

    GildedRose gildedRose(items);
    gildedRose.updateQuality();

    ASSERT_EQ(4, gildedRose.items[0].quality);
}
