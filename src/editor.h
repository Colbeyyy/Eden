#pragma once
#include "types.h"
#include "array.h"
#include "buffer.h"

#define WINDOW_TITLE "YEET"

struct Font;
struct Buffer;
struct Buffer_View;
struct Vector2;

extern Font font;
extern u32 fps;
extern float delta_time;

struct Editor {
	static Editor& get();

	bool is_running = false;
	float delta_time = 0.f;
	u64 last_frame_time = 0;
	u32 fps;

	struct lua_State* lua_state;

	Buffer* create_buffer();
	Buffer* find_buffer(Buffer_ID id);
	bool destroy_buffer(Buffer_ID id);

	inline Buffer_View* get_current_view() { return &main_view; }

	void init();
	void loop();
	void shutdown();

	void on_window_resized(u32 old_width, u32 old_height);
	void on_mousewheel_scrolled(float delta);
	void on_key_pressed(u8 key);
	void on_mouse_down(Vector2 position);
	void on_mouse_up(Vector2 position);
	
	void draw();
private:
	static Editor g_editor;

	Array<struct Buffer> loaded_buffers;
	size_t last_id = 0;

	// @NOTE(Colby): this is super temporary as we don't support multiple views
	Buffer_View main_view;
};



