/******************************************************************************
 * Copyright (C) 2015 by Ralf Kaestner                                        *
 * ralf.kaestner@gmail.com                                                    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#ifndef RQT_MULTIPLOT_PLOT_AXES_CONFIG_H
#define RQT_MULTIPLOT_PLOT_AXES_CONFIG_H

#include <rqt_multiplot/Config.h>
#include <rqt_multiplot/PlotAxisConfig.h>

namespace rqt_multiplot {
  class PlotAxesConfig :
    public Config {
  Q_OBJECT
  public:
    enum Axis {
      X,
      Y
    };
    
    PlotAxesConfig(QObject* parent = 0);
    ~PlotAxesConfig();
    
    PlotAxisConfig* getAxisConfig(Axis axis) const;
    
    void save(QSettings& settings) const;
    void load(QSettings& settings);
    void reset();
    
    void write(QDataStream& stream) const;
    void read(QDataStream& stream);
    
    PlotAxesConfig& operator=(const PlotAxesConfig& src);
    
  private:
    QMap<Axis, PlotAxisConfig*> axisConfig_;
    
  private slots:
    void axisConfigChanged();
  };
};

#endif
