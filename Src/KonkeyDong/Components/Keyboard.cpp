#include "Keyboard.hpp"
#include <SDL_scancode.h>


// KbdEvent
KbdEvent::KbdEvent(KeyboardKey key, KbdEventType type)
	:
	key(key),
	type(type)
{
}

bool KbdEvent::IsPress() const
{
	return type == KbdEventType::Press;
}

bool KbdEvent::IsRelease() const
{
	return type == KbdEventType::Release;
}

bool KbdEvent::IsPressKey(KeyboardKey c) const
{
	return key == c && IsPress();
}

bool KbdEvent::IsReleaseKey(KeyboardKey c) const
{
	return key == c && IsRelease();
}


// Keyboard
Keyboard::Keyboard()
{
	pKeyStates = SDL_GetKeyboardState(&keyStatesLength);
}

bool Keyboard::IsPressed(KeyboardKey key) const
{
	return static_cast<bool>(pKeyStates[key.GetScanCode()]);
}

bool Keyboard::HasEvent() const
{
	return !events.IsEmpty();
}

const KbdEvent Keyboard::GetEvent()
{
	KbdEvent ret = PeekEvent();
	events.Dequeue();
	return ret;
}


void Keyboard::OnClick(KeyboardKey key)
{
	StoreEvent(KbdEvent(key, KbdEvent::KbdEventType::Press));
}

void Keyboard::OnRelease(KeyboardKey key)
{
	StoreEvent(KbdEvent(key, KbdEvent::KbdEventType::Release));
}

void Keyboard::StoreEvent(const KbdEvent& event)
{
	events.Enqueue(event);
}

const KbdEvent& Keyboard::PeekEvent() const
{
	return events.Peek();
}
