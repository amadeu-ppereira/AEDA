#ifndef SRC_JURADO_H_
#define SRC_JURADO_H_

#include <string>
#include <vector>

using namespace std;


class jurado {
	string nome;
	string morada;
	string telemovel;
	string artePerformativa;

public:
	jurado();
	jurado (string nome , string morada , string telemovel , string artePerformativa);
	virtual ~jurado();
};

#endif /* SRC_JURADO_H_ */
