<<<<<<< HEAD
/*
 * CA.h
 *
 *  Created on: Oct 9, 2022
 *      Author: King 45M
 */

#ifndef CA_H_
#define CA_H_

enum{
	CA_waiting,
	CA_driving
}CA_state_id;

/*prototypes*/
void ST_CA_waiting();
void ST_CA_driving();
/*global pointer*/

extern void (*CA_state)();





#endif /* CA_H_ */
=======
/*
 * CA.h
 *
 *  Created on: Oct 9, 2022
 *      Author: King 45M
 */

#ifndef CA_H_
#define CA_H_

enum{
	CA_waiting,
	CA_driving
}CA_state_id;

/*prototypes*/
void ST_CA_waiting();
void ST_CA_driving();
/*global pointer*/

extern void (*CA_state)();





#endif /* CA_H_ */
>>>>>>> 310178b6b37516b4afa740e5a39e05d6b1367656
