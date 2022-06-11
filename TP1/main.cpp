#include "include/files.h"
#include "include/match.h"
#include "include/helper.h"

int main() {
    Match match = Match();
    readFile("entrada.txt", &match);
    match.generateMatchResults();
    VectorCustom<Round> rounds = match.getRounds();
    writeFile("saida.txt", match);

    return 0;
}
