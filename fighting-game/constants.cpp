#include "constants.h"
using namespace std;

const int constants::screen_width = 1080;
const int constants::screen_height = 720;

const string constants::fighter_img_path = "HernandezFighter.png";
const int constants::fighter_img_w = 78;
const int constants::fighter_img_h = 117;

const int constants::fighter_aerial_hitbox_w = 80;
const int constants::fighter_aerial_hitbox_h = 119;
const vector constants::fighter_aerial_right_pos = { (float)0, (float)0 };
const vector constants::fighter_aerial_left_pos = { (float)0, (float)0 };
const int constants::fighter_aerial_damage = 5;
const vector constants::fighter_aerial_knockback = { 2, -2 };
const int constants::fighter_aerial_buffer = 10;
const int constants::fighter_aerial_delay = 0;
const int constants::fighter_aerial_stun = 20;

const int constants::fighter_jab_hitbox_w = 70;
const int constants::fighter_jab_hitbox_h = 20;
const vector constants::fighter_jab_right_pos = { (float) fighter_img_w, (float) (fighter_img_h / 2) - (constants::fighter_jab_hitbox_h / 2) };
const vector constants::fighter_jab_left_pos = { 0 - constants::fighter_jab_hitbox_w, (float) (fighter_img_h / 2) - (constants::fighter_jab_hitbox_h / 2) };
const int constants::fighter_jab_damage = 10;
const vector constants::fighter_jab_knockback = { 2, -2 };
const int constants::fighter_jab_buffer = 60;
const int constants::fighter_jab_delay = 0;
const int constants::fighter_jab_stun = 20;

const int constants::fighter_dash_hitbox_w = 80;
const int constants::fighter_dash_hitbox_h = 119;
const vector constants::fighter_dash_right_pos = { (float)0, (float)0 };
const vector constants::fighter_dash_left_pos = { (float)0, (float)0 };
const int constants::fighter_dash_damage = 8;
const vector constants::fighter_dash_knockback = { 2, -2 };
const int constants::fighter_dash_buffer = 10;
const int constants::fighter_dash_delay = 0;
const int constants::fighter_dash_stun = 20;

const int constants::fighter_special_hitbox_w = 80;
const int constants::fighter_special_hitbox_h = 119;
const vector constants::fighter_special_right_pos = { (float)0, (float)0 };
const vector constants::fighter_special_left_pos = { (float)0, (float)0 };
const int constants::fighter_special_damage = 8;
const vector constants::fighter_special_knockback = { 2, -2 };
const int constants::fighter_special_buffer = 10;
const int constants::fighter_special_delay = 0;
const int constants::fighter_special_stun = 20;

const string constants::steve_img_path = "guy.png";
const int constants::steve_img_w = 78;
const int constants::steve_img_h = 117;

const int constants::steve_aerial_hitbox_w = 80;
const int constants::steve_aerial_hitbox_h = 119;
const vector constants::steve_aerial_right_pos = { (float)0, (float)0 };
const vector constants::steve_aerial_left_pos = { (float)0, (float)0 };
const int constants::steve_aerial_damage = 5;
const vector constants::steve_aerial_knockback = { 2, -2 };
const int constants::steve_aerial_buffer = 10;
const int constants::steve_aerial_delay = 0;
const int constants::steve_aerial_stun = 20;

const int constants::steve_jab_hitbox_w = 70;
const int constants::steve_jab_hitbox_h = 20;
const vector constants::steve_jab_right_pos = { (float)steve_img_w, (float)(steve_img_h / 2) - (constants::steve_jab_hitbox_h / 2) };
const vector constants::steve_jab_left_pos = { 0 - constants::steve_jab_hitbox_w, (float)(steve_img_h / 2) - (constants::steve_jab_hitbox_h / 2) };
const int constants::steve_jab_damage = 10;
const vector constants::steve_jab_knockback = { 2, -2 };
const int constants::steve_jab_buffer = 60;
const int constants::steve_jab_delay = 0;
const int constants::steve_jab_stun = 20;

const int constants::steve_dash_hitbox_w = 80;
const int constants::steve_dash_hitbox_h = 119;
const vector constants::steve_dash_right_pos = { (float)0, (float)0 };
const vector constants::steve_dash_left_pos = { (float)0, (float)0 };
const int constants::steve_dash_damage = 8;
const vector constants::steve_dash_knockback = { 2, -2 };
const int constants::steve_dash_buffer = 10;
const int constants::steve_dash_delay = 0;
const int constants::steve_dash_stun = 20;

const int constants::steve_special_hitbox_w = 80;
const int constants::steve_special_hitbox_h = 119;
const vector constants::steve_special_right_pos = { (float)0, (float)0 };
const vector constants::steve_special_left_pos = { (float)0, (float)0 };
const int constants::steve_special_damage = 8;
const vector constants::steve_special_knockback = { 2, -2 };
const int constants::steve_special_buffer = 10;
const int constants::steve_special_delay = 0;
const int constants::steve_special_stun = 20;