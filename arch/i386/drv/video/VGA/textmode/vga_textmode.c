/**
 ** This file is part of BoneOS.
 **
 **   BoneOS is free software: you can redistribute it and/or modify
 **   it under the terms of the GNU General Public License as published by
 **   the Free Software Foundation, either version 3 of the License, or
 **   (at your option) any later version.

 **   BoneOS is distributed in the hope that it will be useful,
 **   but WITHOUT ANY WARRANTY; without even the implied warranty of
 **   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **   GNU General Public License for more details.

 **   You should have received a copy of the GNU General Public License
 **   along with BoneOS.  If not, see <http://www.gnu.org/licenses/>.
 **
 **  @main_author : Amanuel Bogale
 **  
 **  @contributors:

 **     Amanuel Bogale <amanuel2> : start
 **/  

#include <io/io.h>
#include <misc/status_codes.h>
#include <drv/video/VGA/textmode/80x25/clear.h>
#include <drv/video/VGA/textmode/80x25/putch/putch.h>
#include <drv/video/VGA/textmode/vga_textmode.h>
#include <drv/video/VGA/textmode/update_cursor.h>
#include <drv/video/VGA/textmode/80x25/term_scroll.h>
#include <drv/video/VGA/textmode/cursor.h>




int init_vga_textmode()
{
  outw(CRTC_PORT, (CRSR_START_DEFAULT << 8) | 0x0A);
  outw(CRTC_PORT, (CRSR_END_DEFAULT << 8)   | 0x0B);
  
  return STATUS_OK;
}

vga_textmode_t eightyXtwentyfive_v = 
{
  .w = 80,
  .h = 25,
  .clear = &clear_vga_80_x_25,
  .putch = &putch_vga_80_x_25,
  .name = "VGA_TEXTMODE_80_x_25",
  .update_cursor = &update_cursor_textmode,
  .scroll = &term_scroll_vga_80_x_25,
  .init = &init_vga_textmode
};

vga_textmode_t *vga_textmodes_arr[] = 
{
  &eightyXtwentyfive_v,
  0
};
