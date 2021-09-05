#include "confused.h"

bool Confused::decideAndUpdate(int yPacLoc, int xPacLoc, int pacDirection) {
	update(decide(yPacLoc, xPacLoc, pacDirection));
}
