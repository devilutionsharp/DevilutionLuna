#include <fmt/format.h>
#include <gtest/gtest.h>

#include "drlg_test.hpp"
#include "gendung.h"
#include "multi.h"
#include "quests.h"

using namespace devilution;

namespace {

TEST(Drlg_l4, CreateL4Dungeon_diablo_13_428074402)
{
	LoadExpectedLevelData("diablo/13-428074402.dun");

	InitQuests();
	Quests[Q_WARLORD]._qactive = QUEST_NOTAVAIL;

	TestCreateDungeon(13, 428074402, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(26, 64));
	TestCreateDungeon(13, 428074402, ENTRY_PREV);
	EXPECT_EQ(ViewPosition, Point(47, 79));
	TestCreateDungeon(13, 428074402, ENTRY_TWARPDN);
	EXPECT_EQ(ViewPosition, Point(26, 44));
}

TEST(Drlg_l4, CreateL4Dungeon_diablo_13_594689775)
{
	LoadExpectedLevelData("diablo/13-594689775.dun");

	InitQuests();
	Quests[Q_WARLORD]._qactive = QUEST_INIT;

	TestCreateDungeon(13, 594689775, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(72, 38));
	TestCreateDungeon(13, 594689775, ENTRY_PREV);
	EXPECT_EQ(ViewPosition, Point(32, 40));
	TestCreateDungeon(13, 594689775, ENTRY_TWARPDN);
	EXPECT_EQ(ViewPosition, Point(36, 88));
}

TEST(Drlg_l4, CreateL4Dungeon_diablo_14_717625719)
{
	LoadExpectedLevelData("diablo/14-717625719.dun");

	TestCreateDungeon(14, 717625719, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(90, 64));
	TestCreateDungeon(14, 717625719, ENTRY_PREV);
	EXPECT_EQ(ViewPosition, Point(49, 31));
}

TEST(Drlg_l4, CreateL4Dungeon_diablo_15_1583642716)
{
	LoadExpectedLevelData("diablo/15-1583642716.dun");

	gbIsMultiplayer = false;
	InitQuests();
	Quests[Q_DIABLO]._qactive = QUEST_INIT;

	TestCreateDungeon(15, 1583642716, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(44, 26));
	TestCreateDungeon(15, 1583642716, ENTRY_PREV);
	EXPECT_EQ(ViewPosition, Point(87, 69));

	LoadExpectedLevelData("diablo/15-1583642716-changed.dun");

	Quests[Q_DIABLO]._qactive = QUEST_ACTIVE;

	TestCreateDungeon(15, 1583642716, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(44, 26));
	TestCreateDungeon(15, 1583642716, ENTRY_PREV);
	EXPECT_EQ(ViewPosition, Point(87, 69));
}

TEST(Drlg_l4, CreateL4Dungeon_diablo_15_1256511996)
{
	LoadExpectedLevelData("diablo/15-1256511996.dun");

	gbIsMultiplayer = true;
	InitQuests();

	TestCreateDungeon(15, 1256511996, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(80, 70));
	TestCreateDungeon(15, 1256511996, ENTRY_PREV);
	EXPECT_EQ(ViewPosition, Point(33, 67));
}

TEST(Drlg_l4, CreateL4Dungeon_diablo_16_741281013)
{
	LoadExpectedLevelData("diablo/16-741281013.dun");

	TestCreateDungeon(16, 741281013, ENTRY_MAIN);
	EXPECT_EQ(ViewPosition, Point(58, 42));
}

} // namespace
