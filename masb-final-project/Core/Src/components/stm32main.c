/*
 * stm32main.c
 *
 *  Created on: May 19, 2020
 *      Author: berta
 */

#include "components/stm32main.h"


void setup(void) {

=======
#include "components/pmu.h"
#include "components/masb_comm_s.h"
#include "components/chronoamperometry.h"
#include "components/cyclic_voltammetry.h"

void setup(void) {

	MASB_COMM_S_waitForMessage(); // esperamos un mensaje
	PMU_enable(); // encendemos el pmu

}

void loop(void){


=======
	if (MASB_COMM_S_dataReceived()) { // si recibimos un mensaje

		switch (MASB_COMM_S_command()){ // creamos una estructura para configurar el tipo de comando

			case START_CV_MEAS: // si el host quiere hav¡cer una cv
				cvConfiguration = MASB_COMM_S_getCvConfiguration(); // configuramos la cv con sus parametros
				CV_start(); // ejecutamos la cv

			case START_CA_MEAS: // si el host quiere hav¡cer una ca
				caConfiguration = MASB_COMM_S_getCaConfiguration(); // configuramos la ca con sus parametros
				CA_start; // ejecutamos la ca

			case STOP_MEAS: // si se quiere parar
				break; // paramos

			default:

		}

	}

}
