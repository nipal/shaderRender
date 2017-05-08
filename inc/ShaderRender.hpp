/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShaderRender.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:28:59 by alelievr          #+#    #+#             */
/*   Updated: 2017/05/08 01:05:21 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "shaderpixel.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <string.h>
# include <time.h>
# include <math.h>

#include "ShaderProgram.hpp"
#include "ShaderChannel.hpp"

//#define UNIFORM_DEBUG 1

class ShaderRender
{
	private:
		vec4			mouse = {0, 0, 0, 0};
		vec2			scroll = {0, 0};
		vec4			move = {0, 0, 0, 1};
		vec2			window = {WIN_W, WIN_H};
		vec3			forward = {0, 0, 1};
#if DOUBLE_PRECISION
		dvec4			fractalWindow = {-1, -1, 1, 1}; //xmin, ymin, xmax, ymax
#else
		vec4			fractalWindow = {-1, -1, 1, 1}; //xmin, ymin, xmax, ymax
#endif
		int				keys = 0;
		int				input_pause = 0;

		ShaderProgram	_program;

		vec2			angleAmount;
		int				cursor_mode;
		float			lastPausedTime;
		bool			programLoaded;

		void			updateUniforms(ShaderProgram *p);
		vec3			vec3Cross(vec3 v1, vec3 v2);
		void			updateKeys(void);
		//void			checkFileChanged(t_program *progs);
		void			displayWindowFps(void);

	public:
		ShaderRender(void);
		ShaderRender(const ShaderRender & rhs) = delete;
		ShaderRender &		operator=(ShaderRender & ths) = delete;

		virtual ~ShaderRender(void);

		void				render(GLFWwindow *win);
		void				loadShaderFile(char *file);
		void				initShaderRenders(ShaderRender rs);

		void				windowSizeCallback(int winX, int winY);
		void				framebufferSizeCallback(int width, int height);
		void				scrollCallback(double xOffset, double yOffset);
		void				clickCallback(int button, int action, int mods);
		void				mousePositionCallback(GLFWwindow *win, double x, double y);
		void				keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

		ShaderChannel		*getChannel(int channel);
		//void				updateChannel(const std::string file, int idnex, int mode);
};