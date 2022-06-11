#include "include/files.h"
#include "include/match.h"

int main() {
    Match match = Match();
    readFile("entrada.txt", &match);
    match.generateMatchResults();
    writeFile("saida.txt", match);

    return 0;
}
