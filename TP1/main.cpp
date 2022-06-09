#include "include/files.h"
#include "include/match.h"
#include "include/helper.h"

int main() {
    Match match = Match();
    readFile("entrada.txt", &match);
    match.generateMatchResults();
    VectorCustom<Round> rounds = match.getRounds();
    for (int i = 0; i < rounds.length(); ++i) {
        Round r = rounds.get(i);
        r.print();
    }
    writeFile("saida.txt", match);

    return 0;
}
