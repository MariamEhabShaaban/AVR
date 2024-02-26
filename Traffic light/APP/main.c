/*
 * main.c
 *
 *  Created on: Feb 22, 2024
 *      Author: repair
 */


#include "AAP.h"

int main() {

	traffic_light_init();

	while (1) {

		cars();

	}

	return 0;
}

