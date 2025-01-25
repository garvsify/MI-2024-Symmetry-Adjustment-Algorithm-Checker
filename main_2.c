#include <stdio.h>
#include <stdint.h>

#include "system.h"

//CONSTANTS
const uint16_t sine_wavetable[512]={512,518,524,530,537,543,549,555,562,568,574,580,587,593,599,605,611,617,624,630,636,642,648,654,660,666,672,678,684,690,696,701,707,713,719,725,730,736,741,747,753,758,764,769,774,780,785,790,796,801,806,811,816,821,826,831,836,841,846,850,855,860,864,869,873,878,882,886,890,895,899,903,907,911,915,919,922,926,930,933,937,940,944,947,950,953,957,960,963,966,968,971,974,977,979,982,984,986,989,991,993,995,997,999,1001,1003,1004,1006,1008,1009,1011,1012,1013,1014,1015,1017,1017,1018,1019,1020,1021,1021,1022,1022,1022,1023,1023,1023,1023,1023,1023,1023,1022,1022,1022,1021,1021,1020,1019,1018,1017,1017,1015,1014,1013,1012,1011,1009,1008,1006,1004,1003,1001,999,997,995,993,991,989,986,984,982,979,977,974,971,968,966,963,960,957,953,950,947,944,940,937,933,930,926,922,919,915,911,907,903,899,895,890,886,882,878,873,869,864,860,855,850,846,841,836,831,826,821,816,811,806,801,796,790,785,780,774,769,764,758,753,747,741,736,730,725,719,713,707,701,696,690,684,678,672,666,660,654,648,642,636,630,624,617,611,605,599,593,587,580,574,568,562,555,549,543,537,530,524,518,512,505,499,493,486,480,474,468,461,455,449,443,436,430,424,418,412,406,399,393,387,381,375,369,363,357,351,345,339,333,327,322,316,310,304,298,293,287,282,276,270,265,259,254,249,243,238,233,227,222,217,212,207,202,197,192,187,182,177,173,168,163,159,154,150,145,141,137,133,128,124,120,116,112,108,104,101,97,93,90,86,83,79,76,73,70,66,63,60,57,55,52,49,46,44,41,39,37,34,32,30,28,26,24,22,20,19,17,15,14,12,11,10,9,8,6,6,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,6,6,8,9,10,11,12,14,15,17,19,20,22,24,26,28,30,32,34,37,39,41,44,46,49,52,55,57,60,63,66,70,73,76,79,83,86,90,93,97,101,104,108,112,116,120,124,128,133,137,141,145,150,154,159,163,168,173,177,182,187,192,197,202,207,212,217,222,227,233,238,243,249,254,259,265,270,276,282,287,293,298,304,310,316,322,327,333,339,345,351,357,363,369,375,381,387,393,399,406,412,418,424,430,436,443,449,455,461,468,474,480,486,493,499,505};
const uint16_t tri_wavetable[512]={512,516,520,524,528,532,536,540,544,548,552,556,560,564,568,572,576,580,584,588,592,596,600,604,608,612,616,620,624,628,632,636,640,644,648,652,656,660,664,668,672,676,680,684,688,692,696,700,704,708,712,716,720,724,728,732,736,740,744,748,752,756,760,764,768,771,775,779,783,787,791,795,799,803,807,811,815,819,823,827,831,835,839,843,847,851,855,859,863,867,871,875,879,883,887,891,895,899,903,907,911,915,919,923,927,931,935,939,943,947,951,955,959,963,967,971,975,979,983,987,991,995,999,1003,1007,1011,1015,1019,1023,1019,1015,1011,1007,1003,999,995,991,987,983,979,975,971,967,963,959,955,951,947,943,939,935,931,927,923,919,915,911,907,903,899,895,891,887,883,879,875,871,867,863,859,855,851,847,843,839,835,831,827,823,819,815,811,807,803,799,795,791,787,783,779,775,771,767,763,759,755,751,747,743,739,735,731,727,723,719,715,711,707,703,699,695,691,687,683,679,675,671,667,663,659,655,651,647,643,639,635,631,627,623,619,615,611,607,603,599,595,591,587,583,579,575,571,567,563,559,555,551,547,543,539,535,531,527,523,519,515,512,508,504,500,496,492,488,484,480,476,472,468,464,460,456,452,448,444,440,436,432,428,424,420,416,412,408,404,400,396,392,388,384,380,376,372,368,364,360,356,352,348,344,340,336,332,328,324,320,316,312,308,304,300,296,292,288,284,280,276,272,268,264,260,256,252,248,244,240,236,232,228,224,220,216,212,208,204,200,196,192,188,184,180,176,172,168,164,160,156,152,148,144,140,136,132,128,124,120,116,112,108,104,100,96,92,88,84,80,76,72,68,64,60,56,52,48,44,40,36,32,28,24,20,16,12,8,4,0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,276,280,284,288,292,296,300,304,308,312,316,320,324,328,332,336,340,344,348,352,356,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,452,456,460,464,468,472,476,480,484,488,492,496,500,504,508};
const uint16_t TIM16_prescalers[6] = {2048, 1024, 512, 256, 128, 64}; //2048 is used only by base prescaler index == 1 during symmetry adjustment

//VARIABLE DEFINITIONS
volatile uint16_t raw_prescaler_value = 0;
volatile uint16_t raw_start_value_value = 0;
volatile uint16_t symmetry_value = 0;
volatile uint32_t N_raw = 0;
volatile uint32_t N_sym_first_halfcycle = 0;
volatile uint32_t N_sym_second_halfcycle = 0;
volatile uint32_t N_sym_first_halfcycle_first_measurement = 0;
volatile uint32_t N_sym_first_halfcycle_second_measurement = 0;
volatile uint32_t N_sym_second_halfcycle_first_measurement = 0;
volatile uint32_t N_sym_second_halfcycle_second_measurement = 0;
volatile uint32_t N_sym = 0;
volatile uint8_t flags[34] = {0};
volatile uint8_t flags_per_index[34][512] = {{0}};
volatile uint16_t MPL = 0;
volatile uint16_t MPS = 0;

//STRUCT VARIABLES
struct Params params = {0};

int main() {

	//params.waveshape = SINE_MODE;
	params.waveshape = SQUARE_MODE; //use square wave since the lengthen and shorten regimes are done in 0-255 and 256-511 indexes, i.e. easier to debug



    /*for(uint8_t pr = 1; pr < sizeof(TIM16_prescalers); pr++){ //1024 onwards

        raw_prescaler_value = TIM16_prescalers[pr];

        for(uint8_t sv = 0; sv < 128; sv++){

			raw_start_value_value = sv;

            for(uint16_t sy = 0; sy < 256; sy++){

				symmetry_value = sy;*/

				//IF DOING 'SINGLE VALUE IMPLEMENTATION' COMMENT THE BELOW BACK IN, AND COMMENT FOR LOOPS OUT
				raw_prescaler_value = 64;
				raw_start_value_value = 0;
				symmetry_value = 0;

                for(uint16_t j = 0; j < FINAL_INDEX + 1; j++){

                    params.index = j;
                    params.raw_start_value = raw_start_value_value;
                    params.raw_prescaler = raw_prescaler_value;
                    params.symmetry = symmetry_value;

                    Calculate_Next_Main_Oscillator_Values(&params);
                    Process_TIM16_Final_Start_Value_and_Final_Prescaler(&params);

					if(params.index == FIRST_QUADRANT_START_INDEX){ //first halfcycle first index
						
						N_sym_first_halfcycle_first_measurement = params.final_prescaler * (256 - params.final_start_value);
						//printf("N_sym_first_halfcycle: %d\n", N_sym_first_halfcycle);
					}
					else if(params.index == FIRST_QUADRANT_START_INDEX + 1){ //first halfcycle second index

						N_sym_first_halfcycle_second_measurement = params.final_prescaler * (256 - params.final_start_value);
					}
					else if(params.index == THIRD_QUADRANT_START_INDEX){ //second halfcycle first index
						
						N_sym_second_halfcycle_first_measurement = params.final_prescaler * (256 - params.final_start_value);
						//printf("N_sym_second_halfcycle: %d\n", N_sym_second_halfcycle);
					}
					else if(params.index == THIRD_QUADRANT_START_INDEX + 1){ //second halfcycle second index
						
						N_sym_second_halfcycle_second_measurement = params.final_prescaler * (256 - params.final_start_value);
						//printf("N_sym_second_halfcycle: %d\n", N_sym_second_halfcycle);
					}

					for(uint8_t f = 0; f < 34; f++){
						if(flags[f] == 1){
							flags_per_index[f][j] = 1;
							flags[f] = 0;
						}
					}
                }

				N_raw = raw_prescaler_value * (256 - params.raw_start_value);
				N_raw <<= 1; //multiply by two

				N_sym_first_halfcycle = (N_sym_first_halfcycle_first_measurement + N_sym_first_halfcycle_second_measurement) >> 1;
				N_sym_second_halfcycle = (N_sym_second_halfcycle_first_measurement + N_sym_second_halfcycle_second_measurement) >> 1;

				N_sym = N_sym_first_halfcycle + N_sym_second_halfcycle;

				printf("N_sym: %d\n", N_sym);
				printf("N_raw: %d\n", N_raw);
            //}
        //}
    //}
				printf("Raw Prescaler Value: %d\n", raw_prescaler_value);
				printf("Raw Start Value: %d\n", raw_start_value_value);
				printf("Symmetry Value: %d\n", symmetry_value);
				printf("Manipulated Shorten Period Value: %d\n", MPS);
				printf("Manipulated Lengthen Period Value: %d\n", MPL);

				for(uint8_t g = 0; g < 34; g++){
					printf("Flag: %d\n", g);
					for(uint16_t h = 0; h < 512; h++){
						printf("%d, ", flags_per_index[g][h]);
					}
					printf("\n");
				}
			

    return 0;
}

uint8_t Calculate_Next_Main_Oscillator_Values(struct Params* params_ptr){

	if(params_ptr->index == FINAL_INDEX + 1){
		params_ptr->index = 0;
	}

	if(params_ptr->index == FIRST_QUADRANT_START_INDEX){
		params_ptr->quadrant = FIRST_QUADRANT;
		params_ptr->halfcycle = FIRST_HALFCYCLE;
	}
	else if(params_ptr->index == SECOND_QUADRANT_START_INDEX){
		params_ptr->quadrant = SECOND_QUADRANT;
		params_ptr->halfcycle = FIRST_HALFCYCLE;
	}
	else if(params_ptr->index == THIRD_QUADRANT_START_INDEX){
		params_ptr->quadrant = FIRST_QUADRANT;
		params_ptr->halfcycle = SECOND_HALFCYCLE;
	}
	else if(params_ptr->index == FOURTH_QUADRANT_START_INDEX){
		params_ptr->quadrant = SECOND_QUADRANT;
		params_ptr->halfcycle = SECOND_HALFCYCLE;
	}

    return 1;
}

uint8_t Process_TIM16_Final_Start_Value_and_Final_Prescaler(struct Params* params_ptr){

    #if SYMMETRY_ON_OR_OFF == ON

		enum TIM16_final_start_value_Oscillation_Mode TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
		enum Symmetry_Type symmetry_type_for_halfcycle = SHORTEN;

		uint8_t pot_rotation_corrected = 0;
		enum Symmetry_Status symmetry_status = CW;

		//DETERMINE IF CW OR CCW SYMMETRY POT ROTATION
		if(params_ptr->symmetry < SYMMETRY_ADC_HALF_SCALE){ //adc = 0-127
			symmetry_status = CW;
		}
		else{ //adc is 128-255
			symmetry_status = CCW;
		}

		//DETERMINE WHETHER TO SHORTEN OR LENGTHEN BASED ON CURRENT INDEX AND SYMMETRY POT POSITION
		if((params_ptr->waveshape == SINE_MODE) || (params_ptr->waveshape == TRIANGLE_MODE)){

			if((params_ptr->halfcycle == FIRST_HALFCYCLE && params_ptr->quadrant == FIRST_QUADRANT) || (params_ptr->halfcycle == SECOND_HALFCYCLE && params_ptr->quadrant == SECOND_QUADRANT)){

				if(symmetry_status == CW){

					symmetry_type_for_halfcycle = LENGTHEN;
				}
				else{

					symmetry_type_for_halfcycle = SHORTEN;
				}
			}
			else if((params_ptr->halfcycle == FIRST_HALFCYCLE && params_ptr->quadrant == SECOND_QUADRANT) || (params_ptr->halfcycle == SECOND_HALFCYCLE && params_ptr->quadrant == FIRST_QUADRANT)){

				if(symmetry_status == CW){

					symmetry_type_for_halfcycle = SHORTEN;
				}
				else{

					symmetry_type_for_halfcycle = LENGTHEN;
				}
			}
		}
		else if(params_ptr->waveshape == SQUARE_MODE){

			if(params_ptr->halfcycle == FIRST_HALFCYCLE){

				if(symmetry_status == CW){

					symmetry_type_for_halfcycle = LENGTHEN;
				}
				else{

					symmetry_type_for_halfcycle = SHORTEN;
				}
			}
			else{

				if(symmetry_status == CW){

					symmetry_type_for_halfcycle = SHORTEN;
				}
				else{

					symmetry_type_for_halfcycle = LENGTHEN;
				}
			}
		}

		if(symmetry_status == CW){

			pot_rotation_corrected = SYMMETRY_ADC_HALF_SCALE - 1 - params_ptr->symmetry;
		}
		else{ //CCW

			pot_rotation_corrected = SYMMETRY_ADC_HALF_SCALE - 1 - (SYMMETRY_ADC_FULL_SCALE - params_ptr->symmetry);
		}

		//HAVE TO BE uin16_t FOR 1ST AND 3RD VARIABLES HERE BECAUSE A uint8_t IS LIMITED TO 255!
		uint16_t two_fifty_six_minus_TIM16_raw_start_value = 256 - params_ptr->raw_start_value;

		uint16_t two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC = two_fifty_six_minus_TIM16_raw_start_value * pot_rotation_corrected;

		uint16_t two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC_and_shifted_by_ADC_bits = (uint16_t)(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC >> SYMMETRY_ADC_NUM_BITS);


		//HAVE TO BE uin16_t HERE BECAUSE A uint8_t IS LIMITED TO 255!
		uint16_t manipulated_period_shorten = two_fifty_six_minus_TIM16_raw_start_value - two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC_and_shifted_by_ADC_bits; //manipulated shorten will always be less than 256

		uint16_t manipulated_period_lengthen = two_fifty_six_minus_TIM16_raw_start_value + two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC_and_shifted_by_ADC_bits; //manipulated lengthen can be greater than 256 up to 381


		if((manipulated_period_lengthen < 256) || ((manipulated_period_lengthen == 256) && (unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) == 0))){

			if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) == 128){

				//remainder is 128, which means two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC_and_shifted_by_ADC_bits ends in 0.5

				//manipulated_period_shorten should oscillate over the halfperiod between manipulated_period_shorten and manipulated_period_shorten - 1; //DONE
				//manipulated_period_lengthen should oscillate over the halfperiod between manipulated_period_lengthen and manipulated_period_lengthen + 1; //DONE

				if(symmetry_type_for_halfcycle == SHORTEN){

					TIM16_final_start_value_oscillation_mode = OSCILLATE_DOWNWARDS;
					flags[0] = 1;
				}
				else if(symmetry_type_for_halfcycle == LENGTHEN){

					TIM16_final_start_value_oscillation_mode = OSCILLATE_UPWARDS;
					flags[1] = 1;
				}
				params_ptr->prescaler_adjust = DO_NOTHING;
			}
			else if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) == 0){

				//remainder is zero, which means both shortened and lengthened manipulated periods have no no remainder

				manipulated_period_shorten = manipulated_period_shorten; //do nothing //DONE
				manipulated_period_lengthen = manipulated_period_lengthen; //do nothing //DONE

				if(symmetry_type_for_halfcycle == SHORTEN){
					TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
					flags[2] = 1;
				}
				else if(symmetry_type_for_halfcycle == LENGTHEN){
					TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
					flags[3] = 1;
				}
				params_ptr->prescaler_adjust = DO_NOTHING;
			}
			else if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) < 128){

				//remainder is less than 128, which means two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC_and_shifted_by_ADC_bits ends in less than 0.5

				manipulated_period_shorten = manipulated_period_shorten; //do nothing //DONE
				manipulated_period_lengthen = manipulated_period_lengthen; //do nothing //DONE

				if(symmetry_type_for_halfcycle == SHORTEN){
					TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
					flags[4] = 1;
				}
				else if(symmetry_type_for_halfcycle == LENGTHEN){
					TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
					flags[5] = 1;
				}
				params_ptr->prescaler_adjust = DO_NOTHING;
			}
			else if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) > 128){

				//remainder is greater than 128, which means two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC_and_shifted_by_ADC_bits ends in more than 0.5

				manipulated_period_shorten = manipulated_period_shorten - 1; //DONE
				manipulated_period_lengthen = manipulated_period_lengthen + 1; //DONE

				if(symmetry_type_for_halfcycle == SHORTEN){
					TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
					flags[6] = 1;
				}
				else if(symmetry_type_for_halfcycle == LENGTHEN){
					TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
					flags[7] = 1;
				}
				params_ptr->prescaler_adjust = DO_NOTHING;
			}
		}

		else if((manipulated_period_lengthen > 256) || ((manipulated_period_lengthen == 256) && (unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) > 0))){

			if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) == 128){

				manipulated_period_shorten = manipulated_period_shorten - 1; //DONE
				//NO NEED TO CHECK IF MANIPULATED_PERIOD_SHORTEN ENDS IN 0.5 AS IN THIS SPECIFIC CONDITION, WE HAVE ELIMINATED THAT POSSIBILITY
				manipulated_period_lengthen = manipulated_period_lengthen + 1; //DONE

				if(unsigned_bitwise_modulo(manipulated_period_lengthen, 1) == 0){

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//DO NOT OSCILLATE BETWEEN VALUES //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[8] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[9] = 1;
					}
				}
				else{

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE
					//manipulated period_lengthened should oscillate over the halfperiod between manipulated_period_lengthen and manipulated_period_lengthen + 1. //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[10] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = OSCILLATE_UPWARDS;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[11] = 1;
					}
				}
			}
			else if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) == 0){

				manipulated_period_shorten = manipulated_period_shorten; //do nothing// //DONE

				if(unsigned_bitwise_modulo(manipulated_period_lengthen, 1) == 0){

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//DO NOT OSCILLATE BETWEEN VALUES //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[12] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[13] = 1;
					}
				}
				else{

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE
					//manipulated period_lengthened should oscillate over the halfperiod between manipulated_period_lengthen and manipulated_period_lengthen + 1. //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[14] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = OSCILLATE_UPWARDS;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[15] = 1;
					}
				}
			}
			else if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) < 128){

				manipulated_period_shorten = manipulated_period_shorten; //do nothing// //DONE
				//NO NEED TO CHECK IF MANIPULATED_PERIOD_SHORTEN ENDS IN 0.5 AS IN THIS SPECIFIC CONDITION, WE HAVE ELIMINATED THAT POSSIBILITY
				manipulated_period_lengthen = manipulated_period_lengthen; //do nothing //DONE

				if(unsigned_bitwise_modulo(manipulated_period_lengthen, 1) == 0){

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//DO NOT OSCILLATE BETWEEN VALUES //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[16] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[17] = 1;
					}
				}
				else{

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE
					//manipulated period_lengthened should oscillate over the halfperiod between manipulated_period_lengthen and manipulated_period_lengthen + 1. //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[18] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = OSCILLATE_UPWARDS;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[19] = 1;
					}
				}
			}
			else if(unsigned_bitwise_modulo(two_fifty_six_minus_TIM16_raw_start_value_multiplied_by_PRC, 8) > 128){

				manipulated_period_shorten = manipulated_period_shorten - 1; //DONE
				//NO NEED TO CHECK IF MANIPULATED_PERIOD_SHORTEN ENDS IN 0.5 AS IN THIS SPECIFIC CONDITION, WE HAVE ELIMINATED THAT POSSIBILITY
				manipulated_period_lengthen = manipulated_period_lengthen + 1; //DONE

				if(unsigned_bitwise_modulo(manipulated_period_lengthen, 1) == 0){

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//DO NOT OSCILLATE BETWEEN VALUES //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[20] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[21] = 1;
					}
				}
				else{

					manipulated_period_lengthen = manipulated_period_lengthen >> 1; //DONE
					//prescaler during lengthened halfperiod should be set to half //DONE
					//manipulated period_lengthened should oscillate over the halfperiod between manipulated_period_lengthen and manipulated_period_lengthen + 1. //DONE

					if(symmetry_type_for_halfcycle == SHORTEN){
						TIM16_final_start_value_oscillation_mode = DO_NOT_OSCILLATE;
						params_ptr->prescaler_adjust = DO_NOTHING;
						flags[22] = 1;
					}
					else if(symmetry_type_for_halfcycle == LENGTHEN){
						TIM16_final_start_value_oscillation_mode = OSCILLATE_UPWARDS;
						params_ptr->prescaler_adjust = MULTIPLY_BY_TWO;
						flags[23] = 1;
					}
				}
			}
		}

		MPS = manipulated_period_shorten;
		MPL = manipulated_period_lengthen;

        //DETERMINE THE TIM16_FINAL_START_VALUE FROM MANIPULATED_PERIOD_LENGTHEN/SHORTEN CALCULATED
        //NOTE INVERSE RELATIONSHIP BETWEEN TIM16_FINAL_START_VALUE AND MANIPULATED_PERIOD_LENGTHEN/SHORTEN BECAUSE 256-TIM16_FINAL_START_VALUE = MANIPULATED_PERIOD_LENGTHEN/SHORTEN
        //ODD VALUES OF CURRENT_INDEX WILL FEATURE THE ADJUSTED(OSCILLATED) VALUE
        if(symmetry_type_for_halfcycle == SHORTEN){

            if(TIM16_final_start_value_oscillation_mode == DO_NOT_OSCILLATE){

                params_ptr->final_start_value = 256 - manipulated_period_shorten;
				flags[24] = 1;
            }
            else if(TIM16_final_start_value_oscillation_mode == OSCILLATE_UPWARDS){

                if(unsigned_bitwise_modulo(params_ptr->index, 1) == 0){ //if current index is even

                    params_ptr->final_start_value = 256 - manipulated_period_shorten;
					flags[25] = 1;
                }
                else{ //if current index is odd

                    params_ptr->final_start_value = 256 - (manipulated_period_shorten + 1);
					flags[26] = 1;
                }
            }
            else if(TIM16_final_start_value_oscillation_mode == OSCILLATE_DOWNWARDS){

                if(unsigned_bitwise_modulo(params_ptr->index, 1) == 0){ //if current index is even

                    params_ptr->final_start_value = 256 - manipulated_period_shorten;
					flags[27] = 1;
                }
                else{ //if current index is odd

                    params_ptr->final_start_value = 256 - (manipulated_period_shorten - 1);
					flags[28] = 1;
                }
            }
        }
        else if(symmetry_type_for_halfcycle == LENGTHEN){

            if(TIM16_final_start_value_oscillation_mode == DO_NOT_OSCILLATE){

                params_ptr->final_start_value = 256 - manipulated_period_lengthen;
				flags[29] = 1;
            }
            else if(TIM16_final_start_value_oscillation_mode == OSCILLATE_UPWARDS){

                if(unsigned_bitwise_modulo(params_ptr->index, 1) == 0){ //if current index is even

                    params_ptr->final_start_value = 256 - manipulated_period_lengthen;
					flags[30] = 1;
                }
                else{ //if current index is odd

                    params_ptr->final_start_value = 256 - (manipulated_period_lengthen + 1);
					flags[31] = 1;
                }
            }
            else if(TIM16_final_start_value_oscillation_mode == OSCILLATE_DOWNWARDS){

                if(unsigned_bitwise_modulo(params_ptr->index, 1) == 0){ //if current index is even

                    params_ptr->final_start_value = 256 - manipulated_period_lengthen;
					flags[32] = 1;
                }
                else{ //if current index is odd

                    params_ptr->final_start_value = 256 - (manipulated_period_lengthen - 1);
					flags[33] = 1;
                }
            }
        }

        Adjust_TIM16_Prescaler(params_ptr);

    #endif

    return 1;

}

uint32_t unsigned_bitwise_modulo(uint32_t dividend, uint8_t base_2_exponent){

    return dividend & ((1 << base_2_exponent) - 1);
}

uint8_t Adjust_TIM16_Prescaler(struct Params* params_ptr){

    if(params_ptr->prescaler_adjust == MULTIPLY_BY_TWO){
    	params_ptr->final_prescaler = params_ptr->raw_prescaler << 1;
    }
    else if(params_ptr->prescaler_adjust == DO_NOTHING){
    	params_ptr->final_prescaler = params_ptr->raw_prescaler;
    }
    return 1;
}