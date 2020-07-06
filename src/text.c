/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

ui_text create_text(void)
{
    ui_text text;
    text.text = sfText_create();
    text.font = sfFont_createFromFile("assets/font.ttf");
    sfText_setFont(text.text, text.font);
    return (text);
}

void animate_button(sfRenderWindow *window, sfEvent event, sfVector2f scale,
    sfVector2f pos)
{
    sfTexture *button_tex = sfTexture_createFromFile("assets/button.png", NULL);
    sfIntRect anim = {0, 0, 40, 20};
    sfSprite *button_sprite = sfSprite_create();
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);

    if (m_pos.x > pos.x && m_pos.x < (pos.x + (40 * scale.x)) && m_pos.y >
        pos.y && m_pos.y < (pos.y + (20 * scale.y))) {
        anim.top = 20;
        if (event.type == sfEvtMouseButtonPressed)
            anim.top = 40;
    }
    sfSprite_setTextureRect(button_sprite, anim);
    sfSprite_setTexture(button_sprite, button_tex, sfFalse);
    sfSprite_setPosition(button_sprite, pos);
    sfSprite_setScale(button_sprite, scale);
    sfRenderWindow_drawSprite(window, button_sprite, NULL);
    sfSprite_destroy(button_sprite);
    sfTexture_destroy(button_tex);
}

void set_text(objects *object, double const values[], const char *str, int
isButton)
{
    sfVector2f pos = {values[0], values[1]};
    sfVector2f scale = {values[3] / 30, values[2] / 20};
    sfText_setPosition(object->text.text, pos);
    sfText_setString(object->text.text, str);
    sfText_setCharacterSize(object->text.text, values[2]);
    pos.x -= values[3] / 4;
    pos.y += values[2] / 5;
    if (isButton)
        animate_button(object->window, object->event, scale, pos);
    sfRenderWindow_drawText(object->window, object->text.text,
        NULL);
}

void destroy_texts(objects *object)
{
    sfText_destroy(object->text.text);
    sfFont_destroy(object->text.font);
}