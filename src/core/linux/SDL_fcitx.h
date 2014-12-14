
#ifndef _SDL_fcitx_h
#define _SDL_fcitx_h

#include "../../SDL_internal.h"

#include "SDL_stdinc.h"
#include "SDL_rect.h"

extern SDL_bool SDL_Fcitx_Init(void);
extern void SDL_Fcitx_Quit(void);
extern void SDL_Fcitx_SetFocus(SDL_bool focused);
extern void SDL_Fcitx_Reset(void);
extern SDL_bool SDL_Fcitx_ProcessKeyEvent(Uint32 keysym, Uint32 keycode);
extern void SDL_Fcitx_UpdateTextRect(SDL_Rect *rect);
extern void SDL_Fcitx_PumpEvents();

#endif /* _SDL_fcitx_h */

/* vi: set ts=4 sw=4 expandtab: */
