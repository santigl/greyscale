# greyscale
Implementation of different conversion algorithms using OpenCV.

## Spread
For each pixel, it selects one of the RGB components and assigns it to the other two components of the pixel.

## Average
It calculates the average of the three color components and assigns it to all subpixels.

## Weighted sum (Luminance preserving)
All subpixels get the value obtained by: 0.2126*R + 0.7152*G + 0.0722*B
