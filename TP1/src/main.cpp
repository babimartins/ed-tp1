#include "../include/files.h"

int main() {
    Match match = Match();
    readFile("../entrada.txt", &match);
    match.generateMatchResults();
    writeFile("../saida.txt", match);

    return 0;
}
