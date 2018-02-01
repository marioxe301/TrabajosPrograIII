class Rectangulo {
public:
	Rectangulo();
	Rectangulo(int, int);
	void setBase(int);
	void setAltura(int);
	int getBase();
	int getAltura();

	int getArea();
	int getPerimetro();


	void imprimirRectangulo();
private:
	int base, altura;
};


