#include "SDL_ime.h"
#include "SDL_ibus.h"

typedef SDL_bool (*_SDL_IME_Init)();
typedef void (*_SDL_IME_Quit)();
typedef void (*_SDL_IME_SetFocus)(SDL_bool);
typedef void (*_SDL_IME_Reset)();
typedef SDL_bool (*_SDL_IME_ProcessKeyEvent)(Uint32, Uint32);
typedef void (*_SDL_IME_UpdateTextRect)(SDL_Rect *);
typedef void (*_SDL_IME_PumpEvents)();

static _SDL_IME_Init SDL_IME_Init_Real = NULL;
static _SDL_IME_Quit SDL_IME_Quit_Real = NULL;
static _SDL_IME_SetFocus SDL_IME_SetFocus_Real = NULL;
static _SDL_IME_Reset SDL_IME_Reset_Real = NULL;
static _SDL_IME_ProcessKeyEvent SDL_IME_ProcessKeyEvent_Real = NULL;
static _SDL_IME_UpdateTextRect SDL_IME_UpdateTextRect_Real = NULL;
static _SDL_IME_PumpEvents SDL_IME_PumpEvents_Real = NULL;

static void
InitIME()
{
    static SDL_bool inited = SDL_FALSE;

    if (inited == SDL_TRUE)
        return ;

    inited = SDL_TRUE;

    // default to IBus
#ifdef HAVE_IBUS_IBUS_H
     SDL_IME_Init_Real = SDL_IBus_Init;
     SDL_IME_Quit_Real = SDL_IBus_Quit;
     SDL_IME_SetFocus_Real = SDL_IBus_SetFocus;
     SDL_IME_Reset_Real = SDL_IBus_Reset;
     SDL_IME_ProcessKeyEvent_Real = SDL_IBus_ProcessKeyEvent;
     SDL_IME_UpdateTextRect_Real = SDL_IBus_UpdateTextRect;
     SDL_IME_PumpEvents_Real = SDL_IBus_PumpEvents;
#endif
}

SDL_bool
SDL_IME_Init(void)
{
    InitIME();

    if (SDL_IME_Init_Real)
        return SDL_IME_Init_Real();

    return SDL_FALSE;
}

void
SDL_IME_Quit(void)
{
    if (SDL_IME_Quit_Real)
        SDL_IME_Quit_Real();
}

void
SDL_IME_SetFocus(SDL_bool focused)
{
    if (SDL_IME_SetFocus_Real)
        SDL_IME_SetFocus_Real(focused);
}

void
SDL_IME_Reset(void)
{
    if (SDL_IME_Reset_Real)
        SDL_IME_Reset_Real();
}

SDL_bool
SDL_IME_ProcessKeyEvent(Uint32 keysym, Uint32 keycode)
{
    if (SDL_IME_ProcessKeyEvent_Real)
        return SDL_IME_ProcessKeyEvent_Real(keysym, keycode);

    return SDL_FALSE;
}

void
SDL_IME_UpdateTextRect(SDL_Rect *rect)
{
    if (SDL_IME_UpdateTextRect_Real)
        SDL_IME_UpdateTextRect_Real(rect);
}

void
SDL_IME_PumpEvents()
{
    if (SDL_IME_PumpEvents_Real)
        SDL_IME_PumpEvents_Real();
}
