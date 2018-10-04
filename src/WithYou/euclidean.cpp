typedef struct { int g, x, y; } asdf;
asdf euclid(int a, int b){
	asdf r1 = {a, 1, 0}, r2 = {b, 0, 1}, temp;
	while(r2.g > 0){
		int q = r1.g / r2.g;
		temp.g = r1.g % r2.g;
		temp.x = r1.x - q * r2.x;
		temp.y = r1.y - q * r2.y;

		r1 = r2;
		r2 = temp;
	}
	return r1;
}