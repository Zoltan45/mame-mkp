#pragma once

#ifndef __DRAWBGFX_TARGET_MANAGER__
#define __DRAWBGFX_TARGET_MANAGER__

#include <map>
#include <string>

#include <bgfx/bgfx.h>

#include "texturemanager.h"

class bgfx_target;

class target_manager {
public:
    target_manager(texture_manager& textures) : m_textures(textures) { }
    ~target_manager();

	bgfx_target* create_target(std::string name, bgfx::TextureFormat::Enum format, uint32_t width, uint32_t height, bool filter = false);

    // Getters
    bgfx_target* target(std::string name);

private:
    bgfx_target* create_target(std::string name);

    std::map<std::string, bgfx_target*> m_targets;
    texture_manager& m_textures;
};

#endif // __DRAWBGFX_TARGET_MANAGER__