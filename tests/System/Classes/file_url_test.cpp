/** \file url.cpp
 *  \copyright GPLv3
 *  \details Unitests for url.
 *  \author Darcy
 *  \date   2019-2023
 */
#include "a_tbox_main.cpp"
#include "url.hpp"

#if defined(OS_MINGW) || defined(OS_WIN)
url win_c_windows= url_system ("C:/Windows");
url win_c        = url_system ("C:/");
url system_root  = url_system ("%SystemRoot%");
url windir       = url_system ("%windir%");

TEST_CASE ("as_string on windows") {
  string_eq (as_string (win_c), "C:\\");
  string_eq (as_string (win_c_windows), "C:\\Windows");
  string_eq (as_string (system_root), "%SystemRoot%");
  string_eq (as_string (windir), "%windir%");
}
#else
url unix_root= url_system ("/");
url unix_tmp = url_system ("/tmp");

TEST_CASE ("as_string on nix") {
  string_eq (as_string (unix_root), "/");
  string_eq (as_string (unix_tmp), "/tmp");
}
#endif
