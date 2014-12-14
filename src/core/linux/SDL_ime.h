#ifndef _SDL_ime_h
#define _SDL_ime_h

#include "../../SDL_internal.h"

#include "SDL_stdinc.h"
#include "SDL_rect.h"

extern SDL_bool SDL_IME_Init();
extern void SDL_IME_Quit();
extern void SDL_IME_SetFocus(SDL_bool focused);
extern void SDL_IME_Reset();
extern SDL_bool SDL_IME_ProcessKeyEvent(Uint32 keysym, Uint32 keycode);
extern void SDL_IME_UpdateTextRect(SDL_Rect *rect);
extern void SDL_IME_PumpEvents();

#endif /* _SDL_ime_h */
