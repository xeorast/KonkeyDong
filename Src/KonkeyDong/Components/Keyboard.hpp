#pragma once

#include "../Data/Queue.hpp"

#include <SDL_keyboard.h>

struct KeyboardKey
{
public:
	KeyboardKey(SDL_Scancode scancode) :scancode(scancode) {};
	KeyboardKey(SDL_KeyCode keycode) :scancode(SDL_GetScancodeFromKey(keycode)) {};

	SDL_Scancode GetScanCode() const { return scancode; }
	SDL_KeyCode GetKeyCode() const { return (SDL_KeyCode)SDL_GetKeyFromScancode(scancode); }

	bool operator==(const KeyboardKey& other) const { return scancode == other.scancode; }
	bool operator!=(const KeyboardKey& other) const { return scancode != other.scancode; }

private:
	SDL_Scancode scancode;
};

class KbdEvent
{
public:
	enum class KbdEventType
	{
		Press,
		Release
	};
public:
	KbdEvent(KeyboardKey key, KbdEventType type);
	bool IsPress() const;
	bool IsRelease() const;

	bool IsPressKey(KeyboardKey character) const;
	bool IsReleaseKey(KeyboardKey character) const;

private:
	KeyboardKey key;
	KbdEventType type;
};

class Keyboard
{
	friend int main(int argsc, char* args[]);
public:
	Keyboard();
	Keyboard(const Keyboard&) = delete;
	Keyboard operator=(const Keyboard&) = delete;

	bool IsPressed(KeyboardKey key) const;
	bool HasEvent() const;
	const KbdEvent GetEvent();
	const KbdEvent& PeekEvent() const;

private:
	void OnClick(KeyboardKey key);
	void OnRelease(KeyboardKey key);
	void StoreEvent(const KbdEvent& event);

	kd::collections::Queue<KbdEvent> events;
	const Uint8* pKeyStates;
	int keyStatesLength;
};
