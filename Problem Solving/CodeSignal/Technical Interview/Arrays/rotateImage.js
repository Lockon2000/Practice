zip = (...rows) => rows[0].map((_,c)=>rows.map(row=>row[c]))

function rotateImage(a) {
    return zip(...a.reverse())
}
