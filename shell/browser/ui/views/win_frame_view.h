// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_UI_VIEWS_WIN_FRAME_VIEW_H_
#define SHELL_BROWSER_UI_VIEWS_WIN_FRAME_VIEW_H_

#include "shell/browser/ui/views/frameless_view.h"

namespace electron {

class WinFrameView : public FramelessView {
 public:
  static const char kViewClassName[];
  WinFrameView();
  ~WinFrameView() override;

  // Get frame metrics in pixels.
  gfx::Insets GetGlassInsetsInPixels() const;

  // Get frame metrics in DIP.
  gfx::Insets GetGlassInsets() const;
  gfx::Insets GetClientAreaInsets() const;

  // views::NonClientFrameView:
  gfx::Rect GetBoundsForClientView() const override;
  gfx::Rect GetWindowBoundsForClientBounds(
      const gfx::Rect& client_bounds) const override;
  int NonClientHitTest(const gfx::Point& point) override;
  gfx::Size CalculatePreferredSize() const override;

  // views::View:
  const char* GetClassName() const override;

 private:
  HMONITOR GetMonitor() const;

  DISALLOW_COPY_AND_ASSIGN(WinFrameView);
};

}  // namespace electron

#endif  // SHELL_BROWSER_UI_VIEWS_WIN_FRAME_VIEW_H_
