#ifndef HITBOX_H
#define HITBOX_H

#define ERANTZUN1 1
#define ERANTZUN2 2
#define ERANTZUN3 3
#define ERANTZUN4 4

int mapenHitboxak(int tecla);
int HITBOX_mundua(int tecla);
int HITBOX_mundua2(int tecla);
int HITBOX_mundua3(int tecla);
int HITBOX_mundua4(int tecla);
int HITBOX_hasieraEtxea(int tecla);
int HITBOX_npcInRange(GYM* boss);
int galderenHitboxa();
int HITBOX_nibel1(int tecla);
void grabitateaAplikatu_nibel1();
void grabitatea();
int HITBOX_nibel2(int tecla);
void grabitateaAplikatu_nibel2();
int HITBOX_nibel3(int tecla);
void grabitateaAplikatu_nibel3();
int hitground_nibel1();
int hitground_nibel2();
int hitground_nibel3();
#endif
