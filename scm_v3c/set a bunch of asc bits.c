int divider = 1;
int asc_bits = 8
int i = 0;
int wait_counter = 0;
int divider_shifted = 0;
for(divider = 1; divider < 256; divider += 12){
	for(i = 50, divider_shifted = divider; i < 50+asc_bits; ++i, divider_shifted = divider_shifted >> 1){
		if(divider_shifted & 1){
			set_asc_bit(i);
		}
		else{
			clear_asc_bit(i);
		}
	}
	analog_scan_chain_write(&ASC[0]);
	analog_scan_chain_load();
	for(wait_counter = 0; wait_counter < 10000/divider; ++wait_counter);
}