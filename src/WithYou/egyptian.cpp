// egyptian product with modular n
lint egypt(lint x, lint y){
	lint ret = 0;
	lint base = x;
	for(int i=0; i<=60; i++){
		if(y & (1LL<<i)) ret = (ret + base) % n;
		base = (base + base) % n;
	}
	return ret;
}