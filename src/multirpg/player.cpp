#include "player.h"

#include "../player.h"

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <output.h>
#else
#ifdef USE_SDL // This is needed on Windows, SDL wraps main()
#include <SDL.h>
#endif
#endif

namespace multirpg {

player& player::instance() {
	static player pl;
	return pl;
}

void player::run(std::vector<std::string> args) {
#ifdef EMSCRIPTEN
	// Yield on start to ensure async operations (e.g. "mounting" of filesystems) can finish
	// 10ms appears to work already but to be on the safe side better use 100ms
	emscripten_sleep(100);

	Output::IgnorePause(true);
#endif
	Player::Init(std::move(args));
	Player::Run();
#ifdef EMSCRIPTEN
	// Yield on shutdown to ensure async operations (e.g. IDBFS saving) can finish
	emscripten_sleep(100);
#endif
}

}

