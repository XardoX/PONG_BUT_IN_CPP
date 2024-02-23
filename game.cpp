#define is_down(b) input->buttons[b].is_down
#define is_pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define is_released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_pos_x = 0.f;
float player_pos_y = 0.f;

float speed = 50.f;

static void simulate_game(Input *input, float deltaTime)
{
	clear_screen(000000);

	if (is_down(BUTTON_UP)) player_pos_y += deltaTime * speed;
	if (is_down(BUTTON_DOWN)) player_pos_y -= deltaTime * speed;
	if (is_down(BUTTON_RIGHT)) player_pos_x += deltaTime * speed;
	if (is_down(BUTTON_LEFT)) player_pos_x -= deltaTime * speed;

	draw_rect(player_pos_x, player_pos_y, 1, 1, 0x00ff22);
}