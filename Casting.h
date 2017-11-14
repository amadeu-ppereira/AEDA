#ifndef CASTING_H_
#define CASTING_H_

#include "sessao.h"
#include "candidato.h"
#include "jurado.h"



class Casting {
	vector<sessao*> sessoes;
	vector<candidato*>candidatos;
	vector<jurado*> jurados;

public:
	Casting();
	virtual ~Casting();
};

#endif /* CASTING_H_ */
