//------------------------------------------------------------------------------
// u-robot Digital Controller Firmware
//------------------------------------------------------------------------------

#include <stdio.h>
#include <time.h>
#include <rt_misc.h>
#include <stdlib.h>
#include "Memory_map.h"
#include "Int_Handlers.h"
#include "rf_global_vars.h"
#include "scm3C_hardware_interface.h"
#include "scm3_hardware_interface.h"
#include "bucket_o_functions.h"
#include <math.h>
#include "scum_radio_bsp.h"
#include "test_code.h"
#include "./sensor_adc/adc_test.h"

extern unsigned int current_lfsr;

extern char send_packet[127];
extern unsigned int ASC[38];

// Bootloader will insert length and pre-calculated CRC at these memory addresses	
#define crc_value         (*((unsigned int *) 0x0000FFFC))
#define code_length       (*((unsigned int *) 0x0000FFF8))

// Target LC freq = 2.405G
// Divide ratio is currently 480
unsigned int LC_target = 501042; 
unsigned int LC_code = 975;

// HF_CLOCK tuning settings
unsigned int HF_CLOCK_fine = 17;
unsigned int HF_CLOCK_coarse = 3;

// RC 2MHz tuning settings
unsigned int RC2M_coarse = 21;
unsigned int RC2M_fine = 15;
unsigned int RC2M_superfine = 15;

// Receiver clock settings
unsigned int IF_clk_target = 1600000;
unsigned int IF_coarse = 22;
unsigned int IF_fine = 18;

unsigned int cal_iteration = 0;
unsigned int run_test_flag = 0;
unsigned int num_packets_to_test = 1;

unsigned short optical_cal_iteration = 0;
unsigned short optical_cal_finished = 0;

unsigned short doing_initial_packet_search;
unsigned short current_RF_channel;
unsigned short do_debug_print = 0;


//////////////////////////////////////////////////////////////////
// Main Function
//////////////////////////////////////////////////////////////////

int main(void) {
	int t, y;
	unsigned int calc_crc;
//	int divider = 1;
//	int i = 0;
//	int wait_counter = 0;
//	int divider_shifted = 0;
	
	// Set up mote configuration
	printf("Initializing...");
	initialize_mote();
	
	// Check CRC
	printf("\n-------------------\n");
	printf("Validating program integrity..."); 
	
	calc_crc = crc32c(0x0000,code_length);

	if(calc_crc == crc_value){
		printf("CRC OK\n");
	}
	else {
		printf("\nProgramming Error - CRC DOES NOT MATCH - Halting Execution\n");
		while(1);
	}
	
	if (0) {
		printf("Calibrating frequencies...\n");
		
		ANALOG_CFG_REG__10 = 0x78;
		// Enable optical SFD interrupt for optical calibration
		ISER = 0x0800;
		
		// Wait for optical cal to finish
		while(optical_cal_finished == 0) {}
		optical_cal_finished = 0;

		printf("Cal complete\n");
	}

	

	// printf("Hello new world!\n");
	// while(1) {
	// 	for(t=0; t<10000; t++);
	// }
	printf("Hello new world!\n");	
	

	while(1) {
		//for(divider = 1; divider < 256; divider += 12){
			
//		divider = 255;
//		for(i = 50, divider_shifted = divider; i < 58; ++i, divider_shifted = divider_shifted >> 1){

//				if((divider_shifted & 1) || (52 == i)){
//					set_asc_bit(i);
//				}
//				else{
//					clear_asc_bit(i);
//				}
//		}
//			analog_scan_chain_write(&ASC[0]);
//			analog_scan_chain_load();
//			for(wait_counter = 0; wait_counter < 1000000/divider; ++wait_counter);
//			clear_asc_bit(914);
//			set_asc_bit(916);
//			analog_scan_chain_write(&ASC[0]);
//			analog_scan_chain_load();
//			for(wait_counter = 0; wait_counter < 1000000/divider; ++wait_counter);
		//}
		
		//printf("before settings divider = 4\n");
		// clear_asc_bit(50);
		// clear_asc_bit(51);
		// clear_asc_bit(52);
		// clear_asc_bit(53);
		// clear_asc_bit(54);
		// clear_asc_bit(55);
		// clear_asc_bit(56);
		// clear_asc_bit(57);
		// Aux LDO  = on via ASC

		for(y=0; 1; y++){
			for(t=0; t<1; t++);
			GPIO_REG__OUTPUT=0x0000;
			//printf("Hello world!\n");
			for(t=0; t<1; t++);
			GPIO_REG__OUTPUT=0xFFFF;
			}

		printf("point\n");
//		set_asc_bit(50);
//		set_asc_bit(51);
//		clear_asc_bit(52);
//		set_asc_bit(53);
//		set_asc_bit(54);
//		set_asc_bit(55);
//		set_asc_bit(56);
//		set_asc_bit(57);
//		// Aux LDO  = off via ASC
//		clear_asc_bit(914);
//	  set_asc_bit(916);
//		analog_scan_chain_write(&ASC[0]);
//		analog_scan_chain_load();
//		
//		for(y=0; y<3; y++){
//			for(t=0; t<10; t++);
//			GPIO_REG__OUTPUT=0x0000;
//			//printf("Hello world!\n");
//			for(t=0; t<10; t++);
//			GPIO_REG__OUTPUT=0xFFFF;

//		}


		 for(y=0; y<1; y++){
		 	for(t=0; t<1; t++);
		 	//GPIO_REG__OUTPUT=0x0000;
		 	//printf("Hello world!\n");
		 	for(t=0; t<1; t++);
		 	//GPIO_REG__OUTPUT=0xFFFF;
		 	}


	}
	
}
