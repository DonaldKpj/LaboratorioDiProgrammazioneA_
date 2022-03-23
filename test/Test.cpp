
#include "gtest/gtest.h"
#include "../Mappa.h"
#include "../Personaggio.h"
#include "../Obiettivo.h"
#include "../Schermo.h"

TEST(DimensioneMappa,Mappatest0 ) {
Mappa map0 = Mappa::crea('a');
ASSERT_EQ(map0.getRows(),28) << "Mappa reading problem: height not calculated correctly.";
ASSERT_EQ(map0.getColumns(),28) << "Mappa reading problem: width not calculated correctly.";
}


TEST(DimensioneMappa, Mappatest1){
Mappa map1 = Mappa::crea('b');
ASSERT_EQ(map1.getRows(),16) << "Mappa piccola reading problem: height not calculated correctly.";
ASSERT_EQ(map1.getColumns(),16) << "Mappa piccola reading problem: width not calculated correctly.";
}

TEST(DimensioneMappa, Mappatest2) {
Mappa map2 = Mappa::crea('c');
ASSERT_EQ(map2.getRows(),16) << "Mappa piccola reading problem: height not calculated correctly.";
ASSERT_EQ(map2.getColumns(),16) << "Mappa piccola reading problem: width not calculated correctly.";
}

TEST(PosizionePersonaggio,check) {
Mappa map2 = Mappa::crea(1);
Personaggio pers = Personaggio::crea(0,15);
Obiettivo obiettivo=Obiettivo(15, 1);
Schermo schermo;
schermo.Astar(obiettivo);
vector<Vector2f> vec = pers.getCoordinate();
ASSERT_EQ(vec[0].x,0);
ASSERT_EQ(vec[0].y,15);
ASSERT_EQ(vec[1].x,1);
ASSERT_EQ(vec[1].y,15);
ASSERT_EQ(vec[2].x,2);
ASSERT_EQ(vec[2].y,15);
}