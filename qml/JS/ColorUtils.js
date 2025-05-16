function withOpacity(color, opacity) { 
    if (typeof color === "string") {
        color = Qt.lighter(color, 1.0)
    }

    return Qt.rgba(color.r, color.g, color.b, opacity);
}
