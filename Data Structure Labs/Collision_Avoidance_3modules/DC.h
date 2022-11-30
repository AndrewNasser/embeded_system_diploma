<<<<<<< HEAD
/*
 *
 * created on: 15/10/2022
 * By: Andrew Nasser
 *
 *
 */
#ifndef DC_H_
#define DC_H_
#include "stdio.h"
#include "stdlib.h"
#include "state.h"
enum DC_STATE{
	DC_IDLE,
	DC_BUSY
};

STATE_define(_DC_IDLE) ;
STATE_define(_DC_BUSY) ;
void DC_INIT();
#endif
=======
/*
 *
 * created on: 15/10/2022
 * By: Andrew Nasser
 *
 *
 */
#ifndef DC_H_
#define DC_H_
#include "stdio.h"
#include "stdlib.h"
#include "state.h"
enum DC_STATE{
	DC_IDLE,
	DC_BUSY
};

STATE_define(_DC_IDLE) ;
STATE_define(_DC_BUSY) ;
void DC_INIT();
#endif
>>>>>>> 310178b6b37516b4afa740e5a39e05d6b1367656
