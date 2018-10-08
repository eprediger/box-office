#ifndef __SERVER_ASIENTO_H__
#define __SERVER_ASIENTO_H__

class Asiento {
public:
	Asiento(const unsigned fila, const char columna);

	Asiento(const Asiento& other);

	~Asiento();

	unsigned get_fila() const;

	char get_columna() const;

	bool esta_reservado() const;

private:
	const unsigned fila;
	const char columna;
	bool ocupado;
};

struct find_by_position {
	find_by_position(const unsigned fil, const char col) :
	_fil(fil), _col(col) {}
	bool operator()(const Asiento& seat) const {
		return ((seat.get_fila() == _fil) && (seat.get_columna() == _col));
	}
private:
	const unsigned _fil;
	const char _col;
};

#endif
