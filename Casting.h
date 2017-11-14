#ifndef CASTING_H_
#define CASTING_H_


class sessao;
class candidato;
#include <string>
#include <vector>


class Casting {
	vector<sessao*> sessoes;
	vector<candidato*>candidatos;
	vector<jurado*> jurados;

public:
	Casting();
	virtual ~Casting();
};

#endif /* CASTING_H_ */
